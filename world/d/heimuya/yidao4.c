// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

#include <localtime.h>
inherit ROOM;
int flag=0;

void create()
{
	set("short","���");
	set("long", @LONG
    ����ͨ�� "������"��������������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
·��ȫ���Ӳ�.

LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao3",
		"north" :__DIR__"yidao5",

	]));

        set("objects",([
                __DIR__"npc/jiao_zhong1" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_search", "search");
}


int do_search(string arg)
{
        mixed t;
        object ob;

        if( arg != "�Ӳ�" ) return 0;

        t = NATURE_D->game_time(1);
        // Can only be found during 11:00 to 14:00
        if( flag || (t[LT_HOUR] < 10) || (t[LT_HOUR] >13) ) {
                message_vision("$N���Ӳݴ���������ȥ������ʲôҲû���ҵ���\n", this_player());
                return 1;
        }
        flag = 1;
        ob = new(__DIR__"obj/gou");
        ob->move(this_player());
        message_vision("$N�ڲݴ���������ȥ�����������һ֧�⹳��\n", this_player());
        return 1;
}

void reset()
{
        flag = 0;
        ::reset();
}

