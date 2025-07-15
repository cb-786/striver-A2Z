bool isValid(string word) {
        if(word.size() < 3) return false;
        bool vowel = false;
        bool cons = false;


        for(const auto & ele : word) {

            if(ele == 'a' || ele == 'A' || ele == 'e' || ele == 'E' || ele == 'i' ||   ele == 'I' || ele == 'o' || ele == 'O' || ele == 'u' || ele == 'U') {
                vowel = true;
            }

            else if((ele>='a' && ele <= 'z' ) || (ele <= 'Z' && ele >= 'A')){
                cons = true;
            }


            if((ele >= '0' && ele <='9') || (ele >='a' && ele <= 'z') || (ele>='A' && ele <='Z')) continue ;

            return false;
        }

        return (cons && vowel);

        

    }