// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��ʯ���");
	set("long", @LONG
	һ�������ɵ���ʯ���,Լ��������������һɫ�Ĵ���ʯ���ɣ���������
�����߶���Ե�ʣ�һ����̦Ҳû�У�����¶��ʯͷ��ԭɫ��
LONG
	);

	set("exits", ([
		"north" :__DIR__"dingfeng11",
                "south" :__DIR__"dingfeng9",
	]));
	set("objects",([
                __DIR__"npc/jiao_zhong6" : 4,
        ]));


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

