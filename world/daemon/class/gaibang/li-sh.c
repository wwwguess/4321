// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("����", ({"li sheng", "li", "sheng"}));
        set("title",MAG "ؤ��" NOR + YEL "�˴�" NOR+ MAG "����" NOR);
        set("gender", "����");
        set("age", 38);
        set("long",
                "����λ���Ը�ֱ����������ؤ��˴����ӡ�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 18);
        set("con", 20);
        set("dex", 23);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_kee", 1500);
        set("max_gin", 300);
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 110);

        set("combat_exp", 800000);

        set_skill("force", 111);
        set_skill("huntian-qigong", 112);
        set_skill("strike", 115);
        set_skill("xianglong-zhang", 105);
	set_skill("blade", 110);
	set_skill("liuhe-dao", 110);
        set_skill("dodge", 110);
        set_skill("xiaoyaoyou", 112);
        set_skill("parry", 112);
        set_skill("staff", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 19, "����");
        setup();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<7)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
        if (ob->query("dai")== 7 )
        {
	        if( ob->query("shen") < 0 ) return;
        	command("say �ã���������һ��һ���˲�����ͽ�ܣ��һ�ϲ���������أ�");
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "ؤ��" NOR + YEL +"�ߴ�" NOR + MAG "����" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");


        if((obj->query("id") == "qingzhu ling")
        && ((string)ob->query("family/family_name")== "ؤ��"))
        {
           if (ob->query("dai")==8)
           {
                ob->set_temp("fight_ok",1);
                command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
            }
            else
            {
                command("say "+ RANK_D->query_respect(ob) +"��λ���ԣ����ǲ��ܱȻ���");
                return 0;
            }
        }
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
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
		command("say ������û�գ�" + RANK_D->query_respect(ob) + "���ԵȻ���ٱȡ�");
		return 0;
	}
        me->set("eff_qi", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("gin",   me->query("max_gin"));
        me->set("force",  me->query("max_force"));

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok");
        me->set("bihua",1);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_kee");
        his_max_qi = ob->query("max_kee");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("kee")*100 / his_max_qi) < 50 )
        {
                command("say ����" + RANK_D->query_respect(ob) +
                        "���ö����ϰ�������ڱ����������г���ͷ�� !\n");
                return 1;
        }

        if (( (int)me->query("kee")*100 / my_max_qi) <= 50 )
        {
                command("say ������ʤ�����������ؤ��ļѵ��� ! ��ϲ���� !\n");
                message_vision("$N����$nһ�������\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
                return 1;
        }


        return 1;
}

void halt()
{
        this_object()->delete("bihua");
        return ;
}
