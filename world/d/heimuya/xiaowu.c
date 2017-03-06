// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ�伫����ͨ��С�ݣ���������������ȴ�Ե���Щ���졣����
ϸ������������ţ�ϣ���������֡����������ǽ�ƺ���Щ���ڲ�ͬҲ
��������ʲô����Ҳ˵������
LONG
        );

	set("exits", ([
		"south" :__DIR__"cdd",
	]));
        create_door("south", "����", "north", DOOR_CLOSED);

	setup();
}


void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if( (arg == "west" )&&(!query("is_here")))
        {
	                 message("vision", 
"�ذ��Ȼ����������������һ����滺���ƶ�����¶��һ�����µĽ��ݡ�\n",
                        this_object() );

	 set("exits/down", __DIR__"midao/midao1");
	 call_out("close_passage", 10);

	 return 1;
	}
	else
	{
	write("��Ҫ��ʲô?\n");
	return 0;
	}	

}
void close_passage()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision", 
"�ذ��Ȼ����������������һ����滺���ƶ����������µ�ͨ����ס�ˡ�\n",
                this_object() );
        delete("exits/down");
}


