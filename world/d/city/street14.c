// Room: /d/city/street14.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
�����Ǿ�ʦ�Ĵ���ϡ������Ǿ�ʦ����һ�ţ������µ�ɮ����
ȥȡ���ؾ��˵ء���Ե�õĻ������Կ��������е���ɮ·����
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"  :    __DIR__"westdoor1",
             "east"  :    __DIR__"street15",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

