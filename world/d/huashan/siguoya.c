// Room: /d/huashan/square.c

inherit ROOM;

void create()
{
        set("short", "˼����");
        set("long", @LONG
�����ڻ�ɽ��ɽ����Ϊ��˼���¡���ͨ����ɽ���ӷ��˴������˼���������޷�
���롣�������������£���ͺͺ�Ĵ�ݲ���������һ����ľ����ɽ������ľ�廪����ɫ
���ġ�ֻ��������һ��С·������ϸһ������·���и�ɽ����������һ�����ڵ���ͷ��
����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"xiaolu4",
        ]));
        set("objects", ([
                CLASS_D("huashan")+"/linghu" : 1 ]));

        set("item_desc", ([
                "ɽ��": "����һ��ɽ��������ں����ġ�\n"
        ]) );
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
        object me;
        me = this_player();
        if( me->query_temp("marks/��1") ) {
                message("vision",me->name() + "���±�ɽ�����˽�ȥ��\n",
                environment(me), ({me}) );
                me->move("/d/huashan/siguoyahoudong");
                message("vision",me->name() + "����±ߵ�ɽ����\n",
                environment(me), ({me}) );
                return 1;
                }
        else {
                write("�Ǹ�ɽ���ں����ģ��������ǲ���ȥ�ĺá�\n");
                return 1;
                }

}
