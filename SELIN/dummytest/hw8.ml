(* Question 1: Parsing *)
let parse (inputexp: string): exptree =
  let sym = ref inputexp.[0] in
  let cursor = ref 0 in

  let getsym () =
    cursor := !cursor + 1;
    sym := inputexp.[!cursor]
  in

  let rec expr (): exptree =
    let t = term() in 
    if !sym = '+' then
      begin
        getsym();
        Expr('+', t, expr())
      end
    else t
      
  and term (): exptree =
    let p = primary() in
    if !sym = '*' then
      begin
        getsym(); 
        Expr('*', p, term())
      end
    else p
      
  and primary (): exptree =
    if !sym = '('
    then begin
      getsym ();
      let result = expr () in
      if !sym <> ')' then
        failwith "Mismatched parens"
      else if !cursor = (String.length inputexp) - 1  then
        result
      else begin
        getsym ();
        result
      end
    end
    else
    if isin !sym charSet then
      if !cursor = (String.length inputexp) - 1 then
        Var !sym
      else
        let result = Var !sym in
        begin
          getsym ();
          result
        end
    else
      failwith "In primary"
  in
  expr ()

(* Question 2: Code Generation *)
let tempstore = ref 0

let codegen (e: exptree) =
  let rec helper ((e: exptree), (tag: char)) =
    match e with
    | Var c -> Printf.printf "LOAD  %c\n" c
    | Expr(op, l, r) -> 
        if tag = '=' then 
          (helper(l,'=');
           match r with
           |Var x -> 
               if op = '+' then Printf.printf "ADD  %c\n" x 
               else Printf.printf "MUL  %c\n" x 
           |Expr(op2, l2, r2) -> helper(r,op)) 
        else 
          begin
            tempstore := !tempstore + 1; 
            Printf.printf "STORE %i\n" !tempstore;
            helper(e,'='); 
            (if (tag = '+') then
               Printf.printf "ADD %i\n" !tempstore
             else
               Printf.printf "MUL %i\n" !tempstore);
            tempstore := !tempstore - 1
          end
  in
  helper (e, '=')
