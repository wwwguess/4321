// Room: /d/city/street17.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
��������ʦ�Ĵ���ϡ��ϱ��Ǿ�ʦ�����ţ��������žͿ�ȥ��
�����򡭡��Ϻ��򡣱��������ţ��������С��������̳���һ��һ
���˼���ȥ�ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
/*             "west"   :    __DIR__"xingchang", */
             "north"  :    __DIR__"bridge",
             "south"  :    __DIR__"southdoor",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

