// liangongfang.c ������
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
        ���������������������ҵط��ż������ţ���λ��ɽ��������ϥ������
�������
LONG
        );
        set("exits", ([
                "west" : __DIR__"houhuayuan1",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 3]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
