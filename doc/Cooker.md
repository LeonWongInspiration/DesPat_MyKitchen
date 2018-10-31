#  API 说明文档
## Factory
### Cooker/CookerFactory
#### API描述
CookerFactory类通过子类PotFactory、OvenFactory和KitchenKnife创建对应的Cooker（Pot、Oven、KitchenKnife）。
#### class diagram
![image](https://github.com/LeonWongInspiration/DesPat_MyKitchen/blob/master/doc/image/Cooker.jpg)

## State
### Cooker/CookerState
#### API描述
Cooker类通过CookerState来表示ON和OFF的状态，同时限制了ON和OFF状态下能调用的方法。
#### class diagram
![image](https://github.com/LeonWongInspiration/DesPat_MyKitchen/blob/master/doc/image/Cooker.jpg)
