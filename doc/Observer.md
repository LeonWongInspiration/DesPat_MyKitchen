#  API 说明文档
## Observer
### Stove / Recipe
#### API描述
Stove类通过Attach和Detach方法与多个Recipe类绑定和解绑。当Stove类与一个新的Recipe类绑定时，它将使用Notify方法告知所有正在绑定的Recipe类，这些类用自身的Update方法来更新状态。
#### Class Diagram
![avatar](/image/Observer.jpg)

