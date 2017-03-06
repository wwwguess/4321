// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "ӭ÷��ջ");
	set("long", @LONG
���ǲ�������������һ�ҿ�ջ����˵��ҵ�����һ������������ˡ���
�����￪��ջ����ϣ������������ԭʧɢ�������ܹ�֪�����������������
��ᡣ���ǵ꿪���꣬��ԭ����������������û�����������˵�һ����Ϣ��
һ�����(sign)�������ڡ�
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"   : __DIR__"octo1",]) );


	set("objects", ([
		__DIR__"npc/waiter" : 1 ]) );


	setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/lasa_b", "???" );

}

string look_sign(object me)
{
	if( wizardp(me) )
		return "����д������Ϊ��� �Ա�һ��С�֣������⡣\n";
	else
		return "����д������Ϊ���\n";
}
