using Flax.Build;

public class SpringArmPluginEditorTarget : GameProjectEditorTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // Reference the modules for editor
        Modules.Add("SpringArmPlugin");
    }
}
