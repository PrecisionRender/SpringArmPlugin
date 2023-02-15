// Copyright © 2023 PrecisionRender. All rights reserved.

using System;
using System.Collections.Generic;
using FlaxEngine;

namespace SpringArmPlugin
{
	/// <summary>
	/// Script used to set up the SprimgArm plugin.
	/// </summary>
	public class SpringArmPlugin : GamePlugin
	{
		/// <summary>
		/// Initializes a new instance of the <see cref="SpringArmPlugin"/> class.
		/// </summary>
		public SpringArmPlugin()
		{
			_description = new PluginDescription
			{
				Name = "SpringArm",
				Category = "Tools",
				Author = "PrecisionRender",
				AuthorUrl = "https://www.youtube.com/@PrecisionRender",
				HomepageUrl = null,
				RepositoryUrl = "https://github.com/PrecisionRender/SpringArmPlugin",
				Description = "A tool that keeps Actors from clipping into collision objects.",
				Version = new Version(1, 0),
				IsAlpha = false,
				IsBeta = false,
			};
		}
	}
}
