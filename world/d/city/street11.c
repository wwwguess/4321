// Room: /d/city/street11.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
�����Ǿ�ʦ�Ĵ�֡������Ǿ�ʦ�����ֳ������ţ�һЩ���˴�
��������ȥ����˵���ŵ�ҹ��Ҳ����Ŷ���ϱ���һƬ��լ��������
�ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"bridge",
	     "north"  :    __DIR__"boots",
             "east"   :    __DIR__"street10",
             "south"  :    __DIR__"house1",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

