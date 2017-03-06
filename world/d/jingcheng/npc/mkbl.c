#include <ansi.h>
int ask_bible(object me);
inherit NPC;
void create()
{
	set_name(YEL"马可菠萝"NOR, ({ "markpolo","mark" }));
	set("long", "他看起来神采奕奕，身材高大，金发碧眼。\n");
	set("gender", "男性");
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
	     YEL"马可菠萝说道：I am a stranger here。\n"NOR,
	     RED"马可菠萝说道：I came from Italian,do you know it?It's very big。\n"NOR,
             GRN"马可菠萝说道：Italian is a beautiful country,blue sea,blue sky,wa...� \n"NOR,
	     BLU"马可菠萝说道：China is a bigger than Italian,It's a great county,I love here。\n"NOR,
	}) );
    set("inquiry",([
                "圣经"  : (: ask_bible :),
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
{    say("马可菠萝说：Sorry!I dont know what did you say，I'm a tourist.\n"
                    "Can you help me a map of jingcheng? \n");

 this_player()->set_temp("marks/马1", 1);
 
        return 1;
}   
int accept_object(object who, object what)
{       
        object obj;

                if( (string)what->query("name") == "京城地图" && !userp(what) && (int)this_player()->query_temp("marks/马1")){
                        tell_object(who,"马可菠萝给你一本圣经。\n");
                        tell_object(who,GRN"马可菠萝说道：Hope you can help me doing missionary work。god bless you!\n"NOR);
                        this_player()->set_temp("marks/马1",0);
                        obj = new("/d/jingcheng/npc/obj/bible");
                        obj->move(who);
                        return 1;
                } 
                
                       
        tell_object(who,"马可菠萝笑眯眯地说道：“Oh,thank you,my friend! \n");
        command("nod "+who->query("id"));
        return 1;
}
            
