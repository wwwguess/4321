// /d/city/street4

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
�����������ھ�ʦ�Ľֵ��ϡ������ǽ����Ͻ��ǵ����ţ�������
�ǵ�����λ�Ժյ�����ĸ�լ�������߲�Զ����̫�׾�¥����������
��ϡ���š�
LONG
        );

        set("exits", ([
                "east":         __DIR__"wumen",
                "west" :        __DIR__"xiangguo/gate",
                "north" :       __DIR__"street5",
                ]));

	set("objects", ([
		__DIR__"npc/walker":	1,
		__DIR__"npc/trader":	1,
		]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

