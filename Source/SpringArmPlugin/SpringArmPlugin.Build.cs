using Flax.Build;
using Flax.Build.NativeCpp;

public class SpringArmPlugin : GameModule
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // C++ scripting enabled
        BuildNativeCode = true;
    }

    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        options.ScriptingAPI.IgnoreMissingDocumentationWarnings = true;
    }
}
