// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
      set("short","�����");
	set("long", @LONG
    ����һ��������ֱ�����������ݵ���ʮ���ۡ�����ͨ��
������������ֱ�ﾩ�ǡ�����ͨ�����Ǳؾ�֮·���������
���Ÿ���ͦ�ε�������·�����������������������ھ�����
����֮��.
LONG
	);

	set("exits", ([
 "southup" :__DIR__"dayidao7",
 "north" :__DIR__"dayidao9",
	]));

        set("objects", ([
                __DIR__"npc/mosh2" : 1,
        ]));
	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

