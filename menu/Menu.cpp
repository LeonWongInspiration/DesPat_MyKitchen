/**
 * @brief menu类，通过command操控灶台和炊具。
 *
 *  @build 201810291440
 */
class Menu {

private Command command;

public Menu(Command command) {
        this.command = command;
    }
/**
     * @brief 灶台放上炊具.
     * @param (Object *) obj: 调用私有函数in（）.
     * @return (): 炊具放上灶台.
     */

public void cookerin(){
        command::in();
    }
    /**
     * @brief 灶台拿下炊具.
     * @param (Object *) obj: 调用私有函数out（）.
     * @return (): 炊具拿下灶台.
     */
public void cookerout(){
        command::out();
    }
    /**
        * @brief 选择炊具.
        * @param (Object *) obj: 调用私有函数choose（）.
        * @return (): 炊具选择.
        */
    public void cookerchoose(){
        command::choose();
    }
    /**
     * @brief 选择烹饪方法.
     * @param (Object *) obj: 调用私有函数method（）.
     * @return (): 烹饪方法选择.
     */
public void cookmethod(){
        command::method();
    }


}