inherit ROOM;

void create()
{
        set("short", "��·");

        set("long", @LONG
����һ����·��·����Լ�ɼ����ᣬ�����ưܡ�������һ����ɽ��
��˵�й�ֳ�û��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"s_gate",
            "south" : __DIR__"rockroad",]));
        set("outdoors", "choyin");

        setup();
        replace_program(ROOM);
}

