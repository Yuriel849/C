class cText {
private:
	char* text;
public:
	cText();
	cText(const cText& newText);
	~cText();
	void set(const char* newText);
	const char* get() const;
	cText& operator=(const char* newText);
};
