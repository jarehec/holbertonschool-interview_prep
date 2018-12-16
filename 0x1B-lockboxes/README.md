# Lockboxes

## Synopsis
Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.  
This method determines if all the boxes can be opened

## Example
```
>> boxes = [[1], [2], [3], [4], []]
>> print(canUnlockAll(boxes))
True
>> boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
>> print(canUnlockAll(boxes))
True  
>> boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
>> print(canUnlockAll(boxes))
False
```

## Authors
* Jared Heck
