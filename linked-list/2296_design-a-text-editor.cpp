
/* Official Solution */
class TextEditor {
private:
    list<char> editor;
    list<char>::iterator cursor;

public:
    TextEditor() {
        cursor = editor.end();
    }

    void addText(string text) {
        for (char c : text) {
            editor.insert(cursor, c);
        }
    }

    int deleteText(int k) {
        int count = 0;
        for (; k > 0 && cursor != editor.begin(); k--) {
            editor.erase(prev(cursor));
            count++;
        }
        return count;
    }

    string cursorLeft(int k) {
        while (k > 0 && cursor != editor.begin()) {
            k--;
            cursor = prev(cursor);
        }
        auto head = cursor;
        for (int i = 0; i < 10 && head != editor.begin(); i++) {
            head = prev(head);
        }
        return string(head, cursor);
    }

    string cursorRight(int k) {
        while (k > 0 && cursor != editor.end()) {
            k--;
            cursor = next(cursor);
        }
        auto head = cursor;
        for (int i = 0; i < 10 && head != editor.begin(); i++) {
            head = prev(head);
        }
        return string(head, cursor);
    }
};



/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

/* Official Solution */
class TextEditor {
private:
    vector<char> left;
    vector<char> right;
public:
    TextEditor() {
        
    }

    void addText(string text) {
        for (char c : text) {
            left.push_back(c);
        }
    }
    
    int deleteText(int k) {
        int n = 0;
        for (; !left.empty() && k > 0; k--) {
            left.pop_back();
            n++;
        }
        return n;
    }
    
    string cursorLeft(int k) {
        while (!left.empty() && k > 0) {
            right.push_back(left.back());
            left.pop_back();
            k--;
        }
        int n = left.size();
        return string(left.begin() + max(0, n - 10), left.end());
    }
    
    string cursorRight(int k) {
        while (!right.empty() && k > 0) {
            left.push_back(right.back());
            right.pop_back();
            k--;
        }
        int n = left.size();
        return string(left.begin() + max(0, n - 10), left.end());
    }
};



/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */