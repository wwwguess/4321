// Room: /d/city/street10.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
�����Ǿ�ʦ�Ĵ�֡������Ǿ�ʦ�Ķ����ţ�һЩ�ս��ǵ�����
����·����Ϣ����ʱ����һ���Ц���������Ϳ��Ե���ʦ�����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"eastdoor2",
             "west"   :    __DIR__"street11",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

