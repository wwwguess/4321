// Room: /d/city/bridge.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������ʦ�����š��������ַǷ����������С���ˣ�ġ�����
�ġ���С������Ӧ�о��С�������ϸѰ�ң�˵����������ʲô��
���챦�ء����Ӻ�ǽ���������Ż������̵Ĺ�棨post����
    ������У�䳡���������͵���ʦ���ġ����Ͻ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"street17",
             "west"   :    __DIR__"street12",
             "east"   :    __DIR__"street11",
             "north"  :    __DIR__"jiaowu",]));
        set("objects", ([
               __DIR__"npc/vendor" :1,
               __DIR__"npc/caker"  :1,
	       __DIR__"npc/dumpling_seller":1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

