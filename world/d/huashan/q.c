// qingke.c

#include <login.h>
inherit ROOM;

void create()
{
        set("short", "���ƺ");
        set("long", @LONG
�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ�����
��������Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�������
��ʯ��·����ʯ��������ʯ������ȥɽ�����գ��ο����ˣ��͸û�ͷ�ˡ�
ԶԶ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪��������������
�ˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northdown" : __DIR__"shaluo",
  		"eastup" : __DIR__"qianchi",
	]));

        set("objects", ([
                CLASS_D("huashan") + "/shi" : 1
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

    if (!::valid_leave(me, dir))
        return 0;

        if ( (string)me->query("family/family_name") =="��ɽ��" )
        {
                if (!me->query("K_record1"))
                {
                        me->set("K_record1", me->query("PKS") + me->query("MKS"));
                        me->set("shen_record1", me->query("shen"));
                        me->set("bad", 0);
                }
                if (((int)me->query("bad") == 0) && ((int)me->query("K_record1") ==((int)me->query("PKS") + (int)me->query("MKS"))))
                {
     			return 1;
                }
                else
                {
                        if((int)me->query("bad") == 0) {
                        if((int)me->query("shen_record1") > (int)me->query("shen"))
                        {
                                me->set("bad", me->query("bad") + 1);
                                if (me->query("bad")<3) write("һ����ɽ�����߹���˵��ʦ�����Ҹ����㣬�������ɽ���Ļ������Ƕ�֪�����ٷ��;������㡣\n");
                        }
                        if((int)me->query("shen_record1") < (int)me->query("shen") && me->query("bad") > 0)
                        {
                                me->set("bad", me->query("bad") -1 );
                                write("һ����ɽ���Ӷ���˵��ʦ����˵�����˺��ºܸ��ˣ����Ե���һ�λ��¡�\n");
                        }
                        me->set("K_record1", me->query("PKS") + me->query("MKS"));
                        me->set("shen_record1", me->query("shen"));
                }
                if ((int)me->query("shen") <= -100) me->set("bad", 3);
                if ((int)me->query("bad") == 3)
                {
                        write("·�ϳ���ܶ໪ɽ���ӣ�����˵����˴���ɽ����ȥɱ�ˣ��õ�����һ�ɽ�޷����㣬���ȥ�����ʦ����\n");
                        if((string)me->query("family/master_id")=="yue buqun" || (string)me->query("family/master_id")=="ning zhongze")
	   			me->move("/d/huashan/shufang");
                        if ((string)me->query("family/master_id")=="lu dayou" || (string)me->query("family/master_id")=="yue lingshan")
                                me->move("/d/huashan/buwei1");
                        if ((string)me->query("family/master_id")=="gao genming")
                                me->move("/d/huashan/xiaolu1");

                }
        else
        {
                me->set("bad", 0);
                me->set("K_record1", 0);
        }
        return 1;
}
