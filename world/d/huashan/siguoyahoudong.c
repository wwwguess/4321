// Room : /d/huashan/siguoyahoudong.c
//by www

inherit ROOM;

void create()
{
        set("short", "˼���º�");
        set("long", @LONG
�����ǻ�ɽ��˼�����Ե�ɽ��������ں����ģ�û��һ����Ӱ��
����������һ�����ƺ������˺ܶ��˻��񶷵Ļ��档�������źܶ���
�ã�ʹ�����һ��������������һ�¶��ڣ����ֺ����л���������ϸ
һ���ƺ����滹�Ǹ�С����
LONG
        );

        set("exits", ([
                   "out" : __DIR__"siguoya",
        ]));

        setup();
        set("no_clean_up", 0);
        setup();


}
int valid_leave(object me, string dir)
{
        if( this_player()->query_temp("marks/��1") ) {
                this_player()->set_temp("marks/��1", 0);
        }
        return 1;
}

void init()
{
        this_player()->set_temp("marks/study",0);
        add_action("do_study", "study");
        add_action("do_south", "south");

}


int do_study(string arg)
{
        object me;

        me = this_player();
        if (me->query_temp("marks/study") == 4) return 0;

        if ( (int)me->query_skill("literate", 1) < 1)
	{
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	me->add("sen", -40);
        me->add("kee",-20);
        me->set_temp("marks/study",me->query_temp("marks/study")+1);
        message_vision("$N��ר���ж������ϵĸ񶷳��档\n", me);

	if((int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)/10 > me->query("combat_exp"))
	{
		write("Ҳ����ȱ��ʵս���飬���ǽ�ϻ��е����������޷���ᡣ\n");
		return 1;
	}

        if ( (int)me->query_skill("sword", 1) < 100)
        {
                me->improve_skill("sword", me->query("int"));
                write("����Ŷ�����ĥ��һ�ض����ƺ��Ի��������е��ĵá�\n");
                me->set_temp("wall_learned",1);
        }


        if ( !me->query_temp("wall_learned") )
        {
                write("����Ŷ�����ĥ��һ�ض�����������������̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
        }
        return 1;
}

int do_south()
{
        object me;
        me = this_player();
	if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 40) 
        {
		write("�����ϱ��Ķ���̫�࣬������̫С�����겻����\n");
                return 1;
	}

        if( (int)me->query_condition("findfeng")==0 || me->query("family/master_id")=="feng qingyang" )
	{

int rm = random(100);
write(sprintf("random %d\n", rm));
                if (rm > 48 || me->query("family/master_id")=="feng qingyang")
        	{
                	message("vision",me->name() + "���ϱߵĶ������˽�ȥ��\n",
	                environment(me), ({me}) );
        	        me->move("/d/huashan/feng");
                	message("vision",me->name() + "����ϱߵĶ��\n",
	                environment(me), ({me}) );
               		this_player()->set_temp("marks/��1", 0);
        	        return 1;
	        }
        	else
	        {
        	        message("vision",me->name() + "���ϱߵĶ������˽�ȥ��\n",
                	environment(me), ({me}) );
	                me->move("/d/huashan/feng1");
                         me->apply_condition("findfeng", 60);
        	        message("vision",me->name() + "����ϱߵĶ��\n",
                	environment(me), ({me}) );
	                this_player()->set_temp("marks/��1", 0);
	                return 1;
        	}
	}
	else 
	{
                 write("������Ѿ���ȥ���ˣ���ô��Ҫ��ȥ��\n");
		return 1;
	}
       
}
