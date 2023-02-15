# Spring Arm Plugin for Flax Engine
A tool that prevents Actors from clipping into colliders. One common use case for a spring arm is to prevent cameras from becoming obstructed by walls.


https://user-images.githubusercontent.com/89754713/219168720-d4ddd090-e03a-4443-9a2d-eec1ddc98ff4.mp4



## Installation

For more details, see [how to install a plugin](https://docs.flaxengine.com/manual/scripting/plugins/plugin-project.html) in the Flax Engine documentation.

1. Create a `Plugins` folder in your game's project directory and close this repository into it: `<game-project>\Plugins\SpringArmPlugin`

2. Add reference to the SpringArmPlugin project in your game by modyfying your game's `<game-project>.flaxproj` file like this:


```json
"References": [
    {
        "Name": "$(EnginePath)/Flax.flaxproj"
    },
    {
        "Name": "$(ProjectPath)/Plugins/SpringArmPlugin/SpringArmPlugin.flaxproj"
    }
]
```

3. If you want to access the SpringArmPlugin from your game's scripts, add this line of code in your game's `Game.Build.cs` file in the `Setup` function:
```cs
public override void Setup(BuildOptions options)
{
    base.Setup(options);
    
    // Add the SpringArmPlugin to the private dependencies of the Game.
    options.PrivateDependencies.Add("SpringArmPlugin");
}
```
Since the plugin is written in C++, you'll also need to build the `SpringArmPlugin` project so that the C# glue is generated. To do so in Visual Studio, open a script in your project, and go to the `Solution Explorer`: 

![image](https://user-images.githubusercontent.com/89754713/219164476-f2395ae4-4d2e-4777-a3f6-49587afa9ed8.png)


For easier access to the API, you can also reference the `SpringArmPlugin` namespace in your script:
```cs
using SpringArmPlugin;
```

Now, the SpringArm plugin should be ready to go!

## Usage

The `SpringArm` works by shooting a physics cast along its backwards direction. If the cast collides with anything, all of the arm's children are moved to the closest point away from the collision. The `SpringArm` is implemented as an Actor that can be added to the scene in the same way as any other Actor in Flax Engine. You can find it by right clicking your Scene window and going to `New/Physics/Spring Arm` or in the Toolbox window under the `Physics` tab. You can use the `SpringArm` like any other Actor in Flax:
```cs
SpringArm _springArm;

/// <inheritdoc/>
public override void OnStart()
{
    _springArm = Actor.As<SpringArm>();
    _springArm.ArmLength = 600;

}
```

## API

The entire API for the `SpringArm` is documented in XML.

## License

This plugin and its source code are available under the [Zlib liscence](https://opensource.org/license/zlib-license-php/).
