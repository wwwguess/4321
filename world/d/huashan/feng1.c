// feng.c
inherit ROOM;
void create()
{
        set("short", "���������");
        set("long", @LONG
�����ڻ�ɽ�ڲ�������û�˵��ˣ����Ƕ�����һ�ˣ����Ŷ�
�ڷ���������ֻ��һ��һ�κ�һ���񴲡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"siguoyahoudong",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
