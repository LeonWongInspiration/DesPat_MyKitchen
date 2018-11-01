/**
 * @brief hearth类，判断炊具和灶台之间的关系。
 *
 *  @build 201810291440
 */
class Hearth {
    /**
     * @brief 判断灶台能否接收炊具.
     * @param (Object *) obj: 与hearth*指针比较.
     * @return (bool): True 表示灶台正在被占用，false表示灶台为空.
     */

    private bool isOccupied=(const Hearth* i)

    public bool getState(){
        return isOccupied;
    }
/**
     * @brief 灶台放上炊具.
     * @param (Object *) obj: 与hearth*指针比较.
     * @return (bool): True 表示灶台正在被占用，false表示灶台为空.
     */
public void in(){
    if Hearth.isOccupied=0;
       Hearth.isOccupied=1;

       else
        return -1;

}
/**
     * @brief 灶台拿下炊具.
     * @param (Object *) obj: 与hearth*指针比较.
     * @return (bool): True 表示灶台正在被占用，false表示灶台为空.
     */
public void out(){
        if Hearth.isOccupied=1;
        Hearth.isOccupied=0;

        else
        return -1;

}
}