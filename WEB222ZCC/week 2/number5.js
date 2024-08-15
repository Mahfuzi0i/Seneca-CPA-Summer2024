function isUnder50(){
    for (let i = 0; i < arguments.length; i++)
        {
            if (arguments[i] > 50)
                {
                    return false;
                }
        }
        return true;
}
console.log(isUnder50(1,2,3,4,5,45));