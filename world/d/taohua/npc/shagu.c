// shagu.c ɵ��
#include <ansi.h>
inherit NPC;
int tell_test();
string ask_me();
int accept(string);
void create()
{
        set_name("ɵ��", ({ "sha gu", "sha", "gu" }));
        set("long", "��һ��ɵͷɵ�Ե����ӣ�������ɵɵ��Ц�š�\n");
        set("title", "�һ�������");
        set("gender", "Ů��");
        set("age", 25);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set_skill("qimen-bagua",50);
        set("combat_exp", random(40000));
        set("chat_chance",20);
        set("chat_msg", ({ 
                "ɵ�ô���˵�����������ֵܣ�˭��������׽�Բذ���\n",
                "ɵ�ô���˵�����������ֵܣ�˭��������׽�Բذ���\n",
                "ɵ�ô���˵�����������ֵܣ�˭��������׽�Բذ���\n",
                "ɵ�ô���˵�����������ֵܣ�˭��������׽�Բذ���\n",
                "ɵ�ô���˵�����������ֵܣ�˭��������׽�Բذ���\n",
                "��ʦүү������һ���������Ű��Ե��飬�Ҷ�˭Ҳ��˵��\n"
        }) );
        set("inquiry", ([
                "׽�Բ�":(: tell_test:),
                "micang" : (: tell_test:),
                "���Ű���":(: ask_me:),  
        ]) );

        setup();
}
void init()
{
       ::init();
        add_action("do_accept","accept");
}         
string ask_me()
{    
  object me,hook;
  me=this_player();
          
        if (query_temp("mark/gived")) return "���Ѿ�����Ū���ˣ���ǧ��Ҫ����ʦү֪��!";
	if (!(me->query_temp("mark/micang2"))) return "��������һ��ɡ�";
                        set_temp("mark/gived",1);
			hook = new(__DIR__"obj/bagua.c");
                        hook->move(me);
                        return "��ʦүү˵�Ȿ�鲻�������ˣ����ֵܱ�˵���Ҹ���ġ�";
                        me->delete_temp("mark/micang2");
         }
int tell_test()
{
        object  me;

        me = this_player(); 
	if (!(present("sha gu",environment()) )  ) return 0;
	if(!(query_temp("mark/micang")))
	{
        command("say �ð��ð�������ϲ��׽�Բ��ˡ����ֵܣ��������档");
        command("say ����ֵܺ�����ʱ��Ӯ�ҿ����������һ�����⡣����Ҳһ��ô����accept yes/no��" );
        me->set_temp("mark/micang",1);
        }
        else
        {
        command( "say ���ֵܣ��������档" );
        }
        return 1;
} 


int do_accept(string arg)
{
    object feng;
    object me; 
    me=this_player();

    if (!(present("sha gu",environment(me)) )  ) return 0;

    if (!arg || (arg!= "yes" && arg !="no")) return 0;
    if (me->is_fighting()) return 0;
    if (!(me->query_temp("mark/micang"))) return 0;
    if (arg=="yes")
    {
        command("say ���ֵܣ�����ץ�ҡ�");
        message_vision( YEL "$N͵͵�����۲��ҿ�һ�ǣ�\n" NOR,me);
        message_vision(  "$N��������������һ��ͻȻ�͵�һ��,��ɵ��ץס��\n" NOR,me);
	me->set_temp("mark/micang2",1);
    }
    else
    {
        command("say ���ֵܣ�����ץ�ҡ�");
        message_vision( YEL "$N͵͵�����۲��ҿ�һ�ǣ�\n" NOR,me);
        message_vision(  "$N��������������һ��ͻȻ�͵�һ��,��ɵ��ץס��\n" NOR,me);

    }

    return 1;
}
void reset()
{
    delete_temp("mark/been_get");
}
