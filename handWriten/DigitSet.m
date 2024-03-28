% Assign label to digit set raw data in 2 variables - data & label
% Data: 2-dim array
% Label: 1-dim array, label for each row in data
classdef DigitSet
    methods (Access = public, Static)
        
        function labelizingData(inputFile, outputFile)
            numberOfCategories = 10;
            dataSize = 420 * numberOfCategories;
            
            rawData = load(inputFile);
            [total dim] = size(rawData);
            dim = dim * 24;
            
            data(1:dataSize, 1:dim) = 0;
            label(1:dataSize) = 0;
            idxByCategory(1:numberOfCategories, 1) = 0;
            dataSizeByCategory(1:numberOfCategories) = 0;
            
            dataIdx = 1;
            idx = 1;
            cat = 1;
            for i=1:total
                if i == total - 1
                   z = 5; 
                end
                data(dataIdx, idx:idx + 17) = rawData(i, 1:18);
                
                idx = idx + 18;
                if (i <= total)
                    if (mod(i,24) == 0)
                        idx = 1;
                        label(dataIdx) = cat;
                        dataSizeByCategory(cat) = dataSizeByCategory(cat) + 1;
                        idxByCategory(cat, dataSizeByCategory(cat)) = dataIdx;
                        if (mod(dataIdx,420) == 0)
                            cat = cat + 1;                        
                        end
                        dataIdx = dataIdx + 1;
                    end                    
                end
            end
            
            save(outputFile, 'data', 'label', 'numberOfCategories', 'dim', 'dataSize', 'idxByCategory', 'dataSizeByCategory');
        end
    end
end