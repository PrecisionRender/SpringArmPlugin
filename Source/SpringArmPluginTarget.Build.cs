using Flax.Build;

public class SpringArmPluginTarget : GameProjectTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for game
        Modules.Add("SpringArmPlugin");
    }
}
