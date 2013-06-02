/** Algorithm Aho-Corasik */

# include <iostream>
# include <map>
# include <vector>
# include <string>
# include <queue>
using namespace std;

class Node;
typedef map<const char, Node *> LinksMap;

class Node /** Class Bora */
{
public:
	LinksMap links;
	Node *fail;  
	Node *term; 
	int out;

public:
	Node(Node *fail_node = NULL)
		: fail(fail_node)
		, term(NULL) 
		, out(-1)
	{ }

	Node* getSuffLink(const char c) const //! Function for suffix link calculating
	{
		LinksMap::const_iterator iter = links.find(c);
		if (iter != links.cend()) {
			return iter->second;
		}
		else {
			return NULL;
		}
	}

	bool isTerminal() const 
	{
		return (out >= 0);
	}
};

class AhoCorasick  /** Class AhoCorasik */
{
public:
	typedef void (*Callback) (const char* substr);
	Node root;
	vector<string> words;
	Node* current_state;

public:
	void addString(const char* const str) //! Substring adding
	{
		Node *current_node = &root;
		for(const char *cp = str; *cp; ++cp) {
			Node *child_node = current_node->getSuffLink(*cp);
			if (!child_node) {
				child_node = new Node(&root);
				current_node->links[*cp] = child_node;
			}
			current_node = child_node;
		}
		current_node->out = words.size();
		words.push_back(str);
	}

	void init() //! Initialization of nodes
	{
		queue<Node *> q;
		q.push(&root);
		while (!q.empty()) {
			Node *current_node = q.front();
			q.pop();
			for (LinksMap::const_iterator iter = current_node->links.cbegin();
				iter != current_node->links.cend(); ++iter)
			{
				const char symbol = iter->first;
				Node *child = iter->second;
				Node *temp_node = current_node->fail;
				while (temp_node) {
					Node *fail_candidate = temp_node->getSuffLink(symbol);
					if (fail_candidate) {
						child->fail = fail_candidate;
						break;
					}
					temp_node = temp_node->fail;
				}
				if (child->fail->isTerminal()) {
					child->term = child->fail;
				}
				else {
					child->term = child->fail->term;
				}
				q.push(child);
			}
		}
	}

	void step(const char c) //! Function for transition computation
	{
		while (current_state) {
			Node *candidate = current_state->getSuffLink(c);
			if (candidate) {
				current_state = candidate;
				return;
			}
			current_state = current_state->fail;
		}
		current_state = &root;
	}

	void printTermsForCurrentState(Callback callback) const 
	{
		if (current_state->isTerminal()) {
			callback(words[current_state->out].c_str());
		}
		Node *temp_node = current_state->term;
		while (temp_node) {
			callback(words[temp_node->out].c_str()); 
			temp_node = temp_node->term;
		}
	}

	void search(const char* str, Callback callback) //! Function of search of substring in line
	{
		current_state = &root;
		for(; *str; ++str) {
			cout << *str << ':' << endl;
			step(*str);
			printTermsForCurrentState(callback);
		}
	}
};

void print(const char* str) /** Output of the found line to the screen */
{
	cout << "found substring " << str << "\n";
}

int main()
{
	AhoCorasick AC;
	char string[50];
	cout << "Input first substring: "; //! Input of substrings
	cin >> string;
	AC.addString(string);
	cout << "Input second substring: ";
	cin >> string;
	AC.addString(string);
	cout << "Input third substring: ";
	cin >> string;
	AC.addString(string);
	AC.init();
	cout << "Input string: "; //! Input of strings
	cin >> string;
	AC.search(string, print); 

	cin.get();

	return 0;
}