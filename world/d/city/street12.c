// Room: /d/city/street12.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
�����Ǿ�ʦ�Ĵ�֣���ʯ�̵�������ܸɾ��������Ǿ�ʦ����
�ֳ������ţ�������ʦ�ɲ��ܲ�ȥŶ���ϱ��Ǿ�ʦ���̳������ϴ�
��һЩ��Ҫ�ķ��˵�ʱ������϶�����ɽ�˺�������ƽʱ�˾���
�ö��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"bridge",
             "west"   :    __DIR__"street13",]));
//             "south"  :    __DIR__"xingchang",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
