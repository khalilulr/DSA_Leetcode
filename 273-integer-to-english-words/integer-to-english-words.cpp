class Solution {
   unordered_map<int, string> digits = {
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"}
};
public:
    string num_to_word(int num){
        int hundredP=num/100;
        string word="";

        if(hundredP){
            word=digits[hundredP]+" Hundred";
        }

        int tensP=num%100;

        if(tensP>0 && tensP<=19){
            if (!word.empty()) word += " ";
            word+=digits[tensP];

        }else if(tensP>19){
            int onesD=tensP/10;
            if (!word.empty()) word += " ";
            word+=digits[onesD*10];
            int lastD=tensP%10;
            
            if(lastD){
                word+=" "+digits[lastD];
            }
        }
        return word;
    }
    string numberToWords(int num) {
       
        //10s 20-90
        //1000,mil,bil
        //2,212,345,678
        //678 => 100's
        //100
        //025
        if(num==0)
            return "Zero";
        //
        //num_to_word(n)
        string ans="";
        string suffix[4]={""," Thousand", " Million", " Billion"};
        int i=0;
        while(num){
            int lastThree=num%1000;

            string word=num_to_word(lastThree); //100000
            if(word!=""){
                word+=suffix[i];
                if (!ans.empty())
                    ans = word + " " + ans;
                else
                    ans = word ;
            }
            i++;
            num=num/1000;
        }
        return ans;
    }
};