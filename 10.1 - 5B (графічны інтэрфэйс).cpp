#include <iostream>

using namespace std;

class Graphics {
protected:
	int coordX;
	int coordY;
	int height;
	int width;
	bool visibility;
public:
	Graphics() {
		coordX = NULL;
		coordY = NULL;
		height = NULL;
		width = NULL;
		visibility = false;
	};
	Graphics(Graphics& graph) {
		coordX = graph.coordX;
		coordY = graph.coordY;
		height = graph.height;
		width = graph.width;
		visibility = graph.visibility;
	};
	Graphics(int X, int Y, int H, int W, bool V) {
		coordX = X;
		coordY = Y;
		height = H;
		width = W;
		visibility = V;
	}
	~Graphics() {}

	void Set_Coords(int X, int Y) {
		coordX = X;
		coordY = Y;
	}
	void Set_Size(int H, int W) {
		height = H;
		width = W;
	}
	void Set_Vis(bool V) {
		visibility = V;
	}

	void Show_data() {
		cout << "Coordinates: X = " << coordX << ", Y = " << coordY << endl;
		cout << "Size: Height is " << height << ", Width is " << width << endl;
		if (visibility == true)
			cout << "The object is visible\n";
		else cout << "The object isn't visible\n";
	}
};

class Ellipse : public Graphics {
private:
	string FillColor;
	string BorderColor;
public:
	Ellipse() : Graphics() {
		cout << "Creating ellipse\n";
		FillColor = "none";
		BorderColor = "none";
	}
	Ellipse(int X, int Y, int H, int W, bool V, string fc, string bc) : Graphics(X, Y, H, W, V) {
		cout << "Creating ellipse\n";
		FillColor = fc;
		BorderColor = bc;
	}
	Ellipse(Ellipse& el) : Graphics(el) {
		cout << "Creating ellipse\n";
		FillColor = el.FillColor;
		BorderColor = el.BorderColor;
	}

	/*void Set_Coords(int X, int Y) {
		Graphics::Set_Coords(X, Y);
	}
	void Set_Size(int H, int W) {
		Graphics::Set_Size(H, W);
	}
	void Set_Vis(bool V) {
		Graphics::Set_Vis(V);
	}*/
	void Set_FillC(string fc) {
		FillColor = fc;
	}
	void Set_BordC(string bc) {
		BorderColor = bc;
	}

	void Show_data() {
		Graphics::Show_data();
		cout << "Fill color is " << FillColor << endl;
		cout << "Border color is " << BorderColor << endl;
	}
};

class Text_Objects : public Graphics {
protected:
	string Text;
	string Text_Color;
public: 
	Text_Objects() : Graphics() {
		Text = "none";
		Text_Color = "none";
	}
	Text_Objects(int X, int Y, int H, int W, bool V, string T, string T_C) : Graphics(X, Y, H, W, V) {
		Text = T;
		Text_Color = T_C;
	}
	Text_Objects(Text_Objects& obj) : Graphics(obj) {
		Text = obj.Text;
		Text_Color = obj.Text_Color;
	}

	void Set_Text(string T) {
		Text = T;
	}
	void Set_Text_Color(string T_C) {
		Text_Color = T_C;
	}

	void Show_data() {
		Graphics::Show_data();
		cout << "Text is " << Text << endl;
		cout << "Text color is " << Text_Color << endl;
	}
};

class HyperlinkLabel : public Text_Objects {
private:
	string URL;
public:
	HyperlinkLabel() : Text_Objects() {
		cout << "Creating hyperlink\n";
		URL = "none";
	}
	HyperlinkLabel(int X, int Y, int H, int W, bool V, string T, string T_C, string url) : Text_Objects(X, Y, H, W, V, T, T_C) {
		cout << "Creating hyperlink\n";
		URL = url;
	}
	HyperlinkLabel(HyperlinkLabel& hll) : Text_Objects(hll) {
		cout << "Creating hyperlink\n";
		URL = hll.URL;
	}

	void Set_Url(string url) {
		URL = url;
	}

	void Show_data() {
		Text_Objects::Show_data();
		cout << "URL is " << URL << endl;
	}
};

int main()
{
	/*Ellipse el1;
	el1.Set_Coords(15, 10);
	el1.Set_Size(1000, 800);
	el1.Set_Vis(false);
	el1.Set_FillC("red");
	el1.Set_BordC("white");
	el1.Show_data();
	
	cout << endl << endl;

	Ellipse el2(21, 32, 600, 400, true, "black", "grey");
	el2.Show_data();

	cout << endl << endl;

	Ellipse el3(el1);
	el3.Show_data();

	cout << endl << endl;

	Ellipse el4;
	el4.Show_data();

	cout << endl << endl;*/

	HyperlinkLabel HLL1;
	HLL1.Show_data();

	cout << endl << endl;

	HyperlinkLabel HLL2 (1, 1, 300, 100, true, "Exams keys", "Uncomprehendable", "https://youtu.be/dQw4w9WgXcQ");
	HLL2.Show_data();

}
