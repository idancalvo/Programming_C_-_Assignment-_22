
/*......................  Accessories Command  ....................*/
enum c_m_d /*the numbering of indexes where information is stored on the command line*/
	{ 
		errors=0, 	/* command[0] error (if it was) */
		E_O_F=1,	/* command[1] */
		opcode=2,	/* command[2] command encoding */
		operand_1=3,	/* command[3] operand_1 */
		operand_2=4,	/* command[4] operand_2 */
		operand_3=5	/* command[5] operand_3 */
	};

enum op_code 
	{
		read_mat=1,	print_mat=2,
		add_mat=3,	sub_mat=4,
		mul_mat=5,	mul_scalar=6,
		trans_mat=7,	stop=8
	};

enum operand 
	{
		MAT_A=1,	MAT_B=2,
		MAT_C=3,	MAT_D=4,
		MAT_E=5,	MAT_F=6
	};

enum errors 
	{
		E_ALL_GOOD=0, 		/* no errore */
		E_opcod_name=1,		/* the command name doesnt exist */
		E_matrix_name=2,	/* the matrix name doesnt exist */
		E_meny_comma=3,		/* too many commas between parameters */
		E_real_number=4,	/* the inserted parameter isnt 'Real' number */
		E_meny_text=5,		/* text at the end of command */
		E_missing_parmeter=6,	/* not enough parameters were entered */
		E_not_scalar=7,
		illegal_comma=8,
		E_non_comma=9,
		E_not_stop=-1	
	};
/*...................................................*/
