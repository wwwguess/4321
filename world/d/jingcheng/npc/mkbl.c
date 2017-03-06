#include <ansi.h>
int ask_bible(object me);
inherit NPC;
void create()
{
	set_name(YEL"��ɲ���"NOR, ({ "markpolo","mark" }));
	set("long", "��������������ȣ���ĸߴ󣬽𷢱��ۡ�\n");
	set("gender", "����");
	set("per", 30);
        set("age",25);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 30000);
	set("shen_type", 1);
	setup();
        carry_object("/d/jingcheng/npc/obj/bible");
	set("chat_chance", 10);
	set("chat_msg", ({
	     YEL"��ɲ���˵����I am a stranger here��\n"NOR,
	     RED"��ɲ���˵����I came from Italian,do you know it?It's very big��\n"NOR,
             GRN"��ɲ���˵����Italian is a beautiful country,blue sea,blue sky,wa...� \n"NOR,
	     BLU"��ɲ���˵����China is a bigger than Italian,It's a great county,I love here��\n"NOR,
	}) );
    set("inquiry",([
                "ʥ��"  : (: ask_bible :),
        ]));
}
void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}
void greeting(object me)
{
        command("say Hi,my friend.Nice to meet you!
        \n");
}                                     
int ask_bible(object who)
{    say("��ɲ���˵��Sorry!I dont know what did you say��I'm a tourist.\n"
                    "Can you help me a map of jingcheng? \n");

 this_player()->set_temp("marks/��1", 1);
 
        return 1;
}   
int accept_object(object who, object what)
{       
        object obj;

                if( (string)what->query("name") == "���ǵ�ͼ" && !userp(what) && (int)this_player()->query_temp("marks/��1")){
                        tell_object(who,"��ɲ��ܸ���һ��ʥ����\n");
                        tell_object(who,GRN"��ɲ���˵����Hope you can help me doing missionary work��god bless you!\n"NOR);
                        this_player()->set_temp("marks/��1",0);
                        obj = new("/d/jingcheng/npc/obj/bible");
                        obj->move(who);
                        return 1;
                } 
                
                       
        tell_object(who,"��ɲ���Ц���е�˵������Oh,thank you,my friend! \n");
        command("nod "+who->query("id"));
        return 1;
}
            
