#include <iostream>
#include <vector>
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

	virtual void Show_data() {
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
		cout << endl;
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
		cout << "Text: " << Text << endl;
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
		cout << "URL: " << URL << endl;
		cout << endl;
	}
};

class TextBox : public Text_Objects {
private:
	bool ReadOnly;
public:
	TextBox() : Text_Objects() {
		cout << "Creating text box\n";
		ReadOnly = true;
	}
	TextBox(int X, int Y, int H, int W, bool V, string T, string T_C, bool r_o) : Text_Objects(X, Y, H, W, V, T, T_C) {
		cout << "Creating text box\n";
		ReadOnly = r_o;
	}
	TextBox(TextBox& tb) : Text_Objects(tb) {
		cout << "Creating text box\n";
		ReadOnly = tb.ReadOnly;
	}

	void Set_ReadOnly(bool r_o) {
		ReadOnly = r_o;
	}

	void Show_data() {
		Text_Objects::Show_data();
		if (ReadOnly == true)
			cout << "You can not edit this object\n";
		else cout << "You can edit this object\n";
		cout << endl;
	}
};

class Button : public Text_Objects {
private:
	string ToolTipText;
public:
	Button() : Text_Objects() {
		cout << "Creating button\n";
		ToolTipText = "none";
	}
	Button(int X, int Y, int H, int W, bool V, string T, string T_C, string T_T_T) : Text_Objects(X, Y, H, W, V, T, T_C) {
		cout << "Creating button\n";
		ToolTipText = T_T_T;
	}
	Button(Button& b) : Text_Objects(b) {
		cout << "Creating button\n";
		ToolTipText = b.ToolTipText;
	}

	void Set_TTT(string T_T_T) {
		ToolTipText = T_T_T;
	}

	void Show_data() {
		Text_Objects::Show_data();
		cout << "Tool tip text: " << ToolTipText << endl;
		cout << endl;
	}
};

class Array {
private:
	vector<Graphics*> arr;
public:
	Array() {

	}
	Array(Array& a) {
		arr = a.arr;
	}

	void Set_Arr() {
		int n;
		cout << "Input total number of objects: ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			int type;
			cout << "Input type of object:\n";
			cout << "Ellipse - 1; Hyperlink - 2; Text box - 3; Button - 4\n";
			cin >> type;

			switch (type) {

			case 1: {
				Ellipse* ell = new Ellipse;
				arr.push_back(ell);
				break;
			}
			case 2: {
				HyperlinkLabel* hll = new HyperlinkLabel;
				arr.push_back(hll);
				break;
			}
			case 3: {
				TextBox* tb = new TextBox;
				arr.push_back(tb);
				break;
			}
			case 4: {
				Button* but = new Button;
				arr.push_back(but);
				break;
			}
			default: {
				cout << "Error";
			}

			}
		}

	}

	void Get_Arr() {
		for (int i = 0; i < arr.size(); i++) {
			(*arr[i]).Show_data();
		}
	}
};


int main()
{
	Array arr1;
	arr1.Set_Arr();

	arr1.Get_Arr();

}
