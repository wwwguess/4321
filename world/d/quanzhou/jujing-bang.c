// Room: /city/biaoju.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
        set("short", "�޾����ܶ�");
        set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ�
��������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ��һֻ
������衣����������д�š��޾���������֣������������վ��Ƿ�����
�ڴ������������ʣ������������Ű��ء�������������˵Ц��
LONG
        );

        set("exits", ([
                "north" : __DIR__"xijie",
        ]));

        set("objects", ([
                __DIR__"npc/bangzhong" : 4,
        ]));

        setup();
        replace_program(ROOM);
}
