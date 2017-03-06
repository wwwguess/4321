// othello.c

inherit ITEM;

#define SQ_EMPTY			0x0000
#define SQ_WHITE			0x0001
#define SQ_BLACK			0x0100
#define SQ_REVERSE(x)		(x ^ 0x0101)

#define STATUS(b, x, y)		((b[y] >> (x)) & (SQ_WHITE | SQ_BLACK))
#define PLACE(b, x, y, c)	b[y] = b[y] | (c << (x)) & ((~SQ_REVERSE(c)) << (x))
#define REVERSE(b, x, y)	b[y] ^= ((SQ_WHITE | SQ_BLACK) << (x))

int *board = ({ 0, 0, 0, 0, 0, 0, 0, 0 });
int current_hand = SQ_BLACK;

void create()
{
	set_name("�ڰ�����", ({ "othello board", "board" }) );
	set_weight(1);
	set("no_get", 1);
	
	PLACE(board, 3, 3, SQ_WHITE);
	PLACE(board, 4, 4, SQ_WHITE);
	PLACE(board, 3, 4, SQ_BLACK);
	PLACE(board, 4, 3, SQ_BLACK);
}

void init()
{
	add_action("do_move", "move");
	add_action("do_wipe", "wipe");
}

string long()
{
	int i, j;
	string msg;

	msg = "��������ʾ����\n   0 1 2 3 4 5 6 7\n";
	for(i=0; i<8; i++) {
		msg += " " + i;
		for(j=0; j<8; j++)
			if( STATUS(board, j, i)==SQ_EMPTY ) 		msg += " .";
			else if( STATUS(board, j, i)==SQ_WHITE ) 	msg += " O";
			else if( STATUS(board, j, i)==SQ_BLACK )	msg += " X";
			else 										msg += " ?";
		msg += "\n";
	}
	if( current_hand == SQ_WHITE )
		msg += "�����ֵ������£��� move white <������> <������>��\n";
	else
		msg += "�����ֵ������£��� move black <������> <������>��\n";
	msg += "���Ҫ���£������� wipe board��\n";

	return msg;
}

int valid_move(int x, int y, int chess)
{
	int i, j;

	// Check if it is empty.
	if( STATUS(board, x, y)!=SQ_EMPTY ) return 0;

	// Check left direction.
	if( (x>1) && STATUS(board, x-1, y)==SQ_REVERSE(chess) ) {
		i = x-1;
		while( i-- ) if( STATUS(board, i, y)!=SQ_REVERSE(chess) ) break;
		if( (i>=0) && STATUS(board, i, y)==chess ) return 1;
	}

	// Check right direction.
	if( (x<6) && STATUS(board, x+1, y)==SQ_REVERSE(chess) ) {
		i = x+1;
		while( i++ < 7 ) if( STATUS(board, i, y)!=SQ_REVERSE(chess) ) break;
		if( (i<=7) && STATUS(board, i, y)==chess ) return 1;
	}

	if( y > 1 ) {
		// Check upper direction.
		if( STATUS(board, x, y-1)==SQ_REVERSE(chess) ) {
			j = y-1;
			while(j--) if( STATUS(board, x, j)!=SQ_REVERSE(chess) ) break;
			if( (j>=0) && STATUS(board, x, j)==chess ) return 1;
		}
		// Check left upper direction.
		if( (x > 1) && STATUS(board, x-1, y-1)==SQ_REVERSE(chess) ) {
			i = x-1;
			j = y-1;
			while( (i--) && (j--) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i>=0) && (j>=0) && STATUS(board, i, j)==chess ) return 1;
		}
		// Check right upper direction.
		if( (x < 6) && STATUS(board, x+1, y-1)==SQ_REVERSE(chess) ) {
			i = x+1;
			j = y-1;
			while( (i++ < 7) && (j--) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i<=7) && (j>=0) && STATUS(board, i, j)==chess ) return 1;
		}
	}
	if( y < 6 ) {
		// Check lower direction.
		if( STATUS(board, x, y+1)==SQ_REVERSE(chess) ) {
			j = y+1;
			while(j++ < 7) if( STATUS(board, x, j)!=SQ_REVERSE(chess) ) break;
			if( (j<=7) && STATUS(board, x, j)==chess ) return 1;
		}
		// Check left lower direction.
		if( (x > 1) && STATUS(board, x-1, y+1)==SQ_REVERSE(chess) ) {
			i = x-1;
			j = y+1;
			while( (i--) && (j++ < 7) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i>=0) && (j<=7) && STATUS(board, i, j)==chess ) return 1;
		}
		// Check right lower direction.
		if( (x < 6) && STATUS(board, x+1, y+1)==SQ_REVERSE(chess) ) {
			i = x+1;
			j = y+1;
			while( (i++ < 7) && (j++ < 7) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i<=7) && (j<=7) && STATUS(board, i, j)==chess ) return 1;
		}
	}
	return 0;
}

int do_move(string arg)
{
	int x, y, chess, i, j;
	string ch;

	if( !arg || sscanf(arg, "%s %d %d", ch, x, y) != 3 )
		return notify_fail("ָ���ʽ��move black|white <������> <������>\n");

	if( ch!="black" && ch!="white" )
		return notify_fail("��Ҫ�º���(black)���ǰ���(white)��\n");

	if( ch=="black" && current_hand!=SQ_BLACK )
		return notify_fail("�����ֵ������£�\n");

	if( ch=="white" && current_hand!=SQ_WHITE )
		return notify_fail("�����ֵ������£�\n");

	if( (x<0) || (y<0) || (x>7) || (y>7) )
		return notify_fail("��Ҫ�������\n");

	if( STATUS(board, x, y)!=SQ_EMPTY ) return notify_fail("�����Ѿ��¹��ˣ�\n");

	if( !valid_move(x, y, current_hand) )
		return notify_fail("�㲻�ܽ����������Ǹ�λ�á�\n");

	message_vision("$N����һ��" + (current_hand==SQ_WHITE ? "����" : "����")
		+ "���� (" + x + ", " + y + ") ��λ�á�\n", this_player() );

	PLACE(board, x, y, current_hand);
	chess = current_hand;
	current_hand = SQ_REVERSE(chess);

	// Check left direction.
	if( (x>1) && STATUS(board, x-1, y)==SQ_REVERSE(chess) ) {
		i = x-1;
		while( i-- ) if( STATUS(board, i, y)!=SQ_REVERSE(chess) ) break;
		if( (i>=0) && STATUS(board, i, y)==chess )
			while(i++ < x-1) REVERSE(board, i, y);
	}

	// Check right direction.
	if( (x<6) && STATUS(board, x+1, y)==SQ_REVERSE(chess) ) {
		i = x+1;
		while( i++ < 7 ) if( STATUS(board, i, y)!=SQ_REVERSE(chess) ) break;
		if( (i<=7) && STATUS(board, i, y)==chess )
			while(i-- > x+1) REVERSE(board, i, y);
	}

	if( y > 1 ) {
		// Check upper direction.
		if( STATUS(board, x, y-1)==SQ_REVERSE(chess) ) {
			j = y-1;
			while(j--) if( STATUS(board, x, j)!=SQ_REVERSE(chess) ) break;
			if( (j>=0) && STATUS(board, x, j)==chess )
				while(j++ < y-1) REVERSE(board, x, j);
		}
		// Check left upper direction.
		if( (x > 1) && STATUS(board, x-1, y-1)==SQ_REVERSE(chess) ) {
			i = x-1;
			j = y-1;
			while( (i--) && (j--) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i>=0) && (j>=0) && STATUS(board, i, j)==chess )
				while( (i++ < x-1) && (j++ < y-1) ) REVERSE(board, i, j);
		}
		// Check right upper direction.
		if( (x < 6) && STATUS(board, x+1, y-1)==SQ_REVERSE(chess) ) {
			i = x+1;
			j = y-1;
			while( (i++ < 7) && (j--) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i<=7) && (j>=0) && STATUS(board, i, j)==chess )
				while( (i-- > x+1) && (j++ < y-1) ) REVERSE(board, i, j);
		}
	}
	if( y < 6 ) {
		// Check lower direction.
		if( STATUS(board, x, y+1)==SQ_REVERSE(chess) ) {
			j = y+1;
			while(j++ < 7) if( STATUS(board, x, j)!=SQ_REVERSE(chess) ) break;
			if( (j<=7) && STATUS(board, x, j)==chess )
				while( j-- > y+1 ) REVERSE(board, x, j);
		}
		// Check left lower direction.
		if( (x > 1) && STATUS(board, x-1, y+1)==SQ_REVERSE(chess) ) {
			i = x-1;
			j = y+1;
			while( (i--) && (j++ < 7) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i>=0) && (j<=7) && STATUS(board, i, j)==chess )
				while( (i++ < x-1) && (j-- > y+1) ) REVERSE(board, i, j);
		}
		// Check right lower direction.
		if( (x < 6) && STATUS(board, x+1, y+1)==SQ_REVERSE(chess) ) {
			i = x+1;
			j = y+1;
			while( (i++ < 7) && (j++ < 7) )	if( STATUS(board, i, j)!=SQ_REVERSE(chess) ) break;
			if( (i<=7) && (j<=7) && STATUS(board, i, j)==chess )
				while( (i-- > x+1) && (j-- > y+1) ) REVERSE(board, i, j);
		}
	}
	return 1;
}

int do_wipe(string arg)
{
	if( arg != "board" ) return 0;

	board = ({ 0, 0, 0, 0, 0, 0, 0, 0 });
	current_hand = SQ_BLACK;
	message_vision("$N�����ָ̻���ԭ״�������������ˡ�\n", this_player());
	PLACE(board, 3, 3, SQ_WHITE);
	PLACE(board, 4, 4, SQ_WHITE);
	PLACE(board, 3, 4, SQ_BLACK);
	PLACE(board, 4, 3, SQ_BLACK);
	return 1;
}
