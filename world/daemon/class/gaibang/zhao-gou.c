// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int accept_object(object ob, object obj);
int accept_fight(object ob);
int checking(object me, object ob);
void halt();

void create()
{
        set_name("赵狗儿", ({"zhao gouer", "zhao", "gouer"}));
        set("title",MAG "丐帮" NOR + YEL "一袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 17);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮一袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));


        set("max_kee", 500);
        set("max_gin", 300);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 30);

        set("combat_exp", 5000);

        set_skill("force", 30);
        set_skill("huntian-qigong", 30);
	set_skill("blade", 30);
	set_skill("liuhe-dao", 30);
        set_skill("hand", 30);
        set_skill("shexing-shou", 30);
        set_skill("dodge", 30);
        set_skill("xiaoyaoyou", 30);
        set_skill("parry", 30);
        set_skill("begging", 30);
        set_skill("stealing", 30);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
	map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 26, "弟子");
        setup();
}

int accept_object(object ob, object obj)
{
        object me = this_object();


        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");


        if((obj->query("id") == "qingzhu ling")
	&& ((string)ob->query("family/family_name")== "丐帮"))
        {	
	   if (ob->query("dai")==1)
	   {
                ob->set_temp("fight_ok",1);
                command("say 好，既然已得到简长老许可，我们就来验证一下武功。");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
	    }
	    else
	    {
		command("say "+ RANK_D->query_respect(ob) +"袋位不对，我们不能比划。");
	    	return 0;
	    }
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
        object me  = this_object();

        if ( !ob->query_temp("fight_ok") ) return 0;
        if (me->is_fighting())
	{
		command("say 我正在没空，" + RANK_D->query_respect(ob) + "可以等会儿再比。");
		return 0;
	}
        me->set("eff_qi", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("gin",   me->query("max_gin"));
        me->set("force",  me->query("max_force"));

       	remove_call_out("checking");
        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok");
	me->set("bihua", 1);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi,i;

        my_max_qi  = me->query("max_kee");
        his_max_qi = ob->query("max_kee");

        if (me->is_fighting() && ob->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

    	if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("kee")*100 / his_max_qi) < 50 )
        {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在本帮诸多弟子中出人头地 !\n");
		me->delete("bihua");
                return 1;
        }

        if (( (int)me->query("kee")*100 / my_max_qi) <= 50 )
        {
                command("say 青出於蓝胜於蓝，不愧是丐帮的佳弟子 ! 恭喜你了 !\n");
                message_vision("$N交给$n一个青竹令。\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
		me->delete("bihua");
                return 1;
        }


        return 1;
}

void halt()
{
	this_object()->delete("bihua");
	return ;
}
