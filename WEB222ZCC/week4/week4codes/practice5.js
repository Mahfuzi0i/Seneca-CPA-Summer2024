function tidy(string) {
    return string.map( e => e.trim() )
}
console.log(tidy(["   Heloo", "  world"]));