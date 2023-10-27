package Flight;

import java.security.InvalidParameterException;

public class Plane{
    public void fly(Turn turn) {
        if (turn == null) {
            throw new InvalidParameterException("Can not perform operation");
        }
        turn.setDirection(turn.getDirection() + turn.getAngle());
    }
}
