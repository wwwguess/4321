// Room: /d/city/jiaowu.c
inherit ROOM;
void create()
{
        set("short", "У�䳡");
        set("long", @LONG
�����Ǿ�ʦ��У�䳡��һЩ���־�����������ҹ��������ɱ��
����˷����������Ÿ�ͷ����Ľ��죬�ڳ������ص�Ѳ�ӡ�ÿ����
��Ҳ���ڴ˾��еģ������������䡢���ܳ�������Ƽ�����ڴ˳���
�˷�ͷ��һʱ���������鳤�����⡢���ϱ���
    ���������ţ��ϱ������ֵ������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"bridge",
             "north"  :    __DIR__"wumen",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

