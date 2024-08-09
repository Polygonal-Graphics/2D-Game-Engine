namespace PE
{
	class Game
	{
	public:

		// Constructors
		Game();

		bool Start();

		// Screen variables
		unsigned int SCREEN_WIDTH = 1920;
		unsigned int SCREEN_HEIGHT = 1080;
		bool FULLSCREEN = false;

	private:
		// Misc. Variables
		class GLFWwindow* window;

		// Initialization functions
		bool WindowInit();
	};
}
