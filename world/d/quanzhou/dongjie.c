// Room: /d/quanzhou/dongjie.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Ȫ�ݵĶ���֡�������һ���ۿڣ���������Գ���������
�������ľ���ݵ�Ȫ�ݷֹݡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"haigang",
               "north" : __DIR__"wgm1",
                "west" : __DIR__"zhongxin",
        ]));


        set("no_clean_up", 0);
        set("valid_startroom", 1);

        setup();
        replace_program(ROOM);
}
