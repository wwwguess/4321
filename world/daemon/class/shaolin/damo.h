int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");

        if (obj->query("id") == "tuijian xin6"
        && ob->query_temp("have_letter") )
        {
                ob->set_temp("apprentice_ok",1);
                command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��")
;
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
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


void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam  = me->query("family");

        string name, new_name;

        name = ob->query("name");
        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������"
)
        {
                 command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "��
����")
        {
                command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�������
����ѧ�ա�");
                return;
        }
        if ( ob_fam["generation"] == 0 )
        {
                command("say �����ӷ�ƶɮ�����������ҵĵ����ˡ�");
                command("recruit " + ob->query("id"));
                command("chat ��������");
                command("chat �ҷ���٤Ĳ���ֵ�һ���ˣ������ϲ�ɺ�");
                return;
        }

        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !")
;
                return;
        }

        if ((int)ob->query_skill("buddhism", 1) < 150) {
                command("say ���������˳����ˣ����������С�");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���������ķ��϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ����
��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        if (ob->query_int() < 45) {
                command("say �ҷ���٤Ĳ����Ǵ�ۣ���������������������졣");
                command("say " + RANK_D->query_respect(ob) + "�����Ի��ǲ�����,
��ذɡ�");
                return;
        }
        if ( ob_fam["generation"] == 36 )
        {
                if ( ob->query_temp("apprentice_ok") )
                {
                        ob->delete_temp("have_letter");
                        ob->delete_temp("apprentice_ok");

                        command("say ��" + ob_fam["master_name"] + "���������ҵ�
�ɣ������� !");
                        command("say �ҷ��ֵô��ˣ����ǿ�ϲ�ɺ� !");

                        new_name = "��" + name[2..3];
                        ob->set("name", new_name+"����");
//			ob->set("combat_exp", ob->query("combat_exp") + 300000);


                        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ
������Ϊ�����ɶ��ֱ����� !");

                        command("chat ����������������");
                        command("chat ƶɮ���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
                        command("recruit " + ob->query("id"));

                }
                else
                {
                        command("say " + RANK_D->query_respect(ob) + "����û����
���ţ�����Խ����ʦ��");
                        return;
                }

        }

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	if( ob->query_skill("buddhism", 1) >= 180)
	{
        	ob->set("title",HIR "����" NOR + CYN "����" NOR);
		return;
	}
       	ob->set("title",HIR "����" NOR + CYN "ʥɮ" NOR);
        return;
}

void re_rank(object student)
{
	if( student->query_skill("buddhism", 1) >= 150)
	{
        	student->set("title",HIR "����" NOR + CYN "����" NOR);
		return;
	}
       	student->set("title",HIR "����" NOR + CYN "ʥɮ" NOR);
        return;
}
