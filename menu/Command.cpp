/**
 * @brief command类，操控灶台和炊具。
 *
 *  @build 201810291440
 */
class Command{

public Command(Cooker cooker){
        this.cooker = cooker;
    }
public Command(Hearth hearth)  {
        this.hearth =hearth;
    }

public void in(){
        hearth::in();
    }
public void out(){
        hearth::out();
    }
public void choose(){
        cooker::choose();
    }
public void method(){
        cooker::method();
    }

private Hearth.hearth;
private Cooker.cooker;

}