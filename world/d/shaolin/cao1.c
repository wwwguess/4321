// Room: cao.c

inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
        ����һƬãã�Ĵ��ԭ��һ�߽�������·���ʧ�˷���
LONG
        );

        set("exits", ([
                "east" : __DIR__"cao2",
                "west" : __DIR__"cao"+(random(6)+1),
                "south" : __DIR__"wherein",
                "north" : __DIR__"cao"+(random(6)+1),
        ]));
        setup();
        replace_program(ROOM);
}
