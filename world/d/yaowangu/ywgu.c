// ywgu.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

string look_board();

void create()
{
	set("short", YEL"ҩ����"NOR);
	set("long", @LONG
	  ������С·�����ߣ�һ��������������ǰ����ǰ��һ������(board)��
һ��Ů������������ǰ�������Ͽ��飬һ�����е����ӡ�
LONG
	);

	set("exits", ([
		"up" : __DIR__"foot.c", 
	 ]));  
	set("objects", ([
		__DIR__"npc/cheng" : 1,
	]));                   
	set("item_desc", ([
		"board" : (: look_board :),
	]));
	setup();
}                   

string look_board()
{
	return YEL"\n���������Ƚ��Ƽ���Ϊ������ݣ��������������£�\n
\n 	���Ǿ�����500000���ϣ��ɽ���һ�����ݣ�����һ�ν��������� ���У�\n
\n 	���ݺ�һ��10000exp,������һ��15000exp,welcome!!!!\n\n"NOR;
}
		

void reset()
{
    ::reset();
    if(query("exits/down"))
    	delete("exits/down");
}


                                                