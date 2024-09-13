/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
package org.apache.airavata.helix.core.support.adaptor;

import org.apache.airavata.agents.api.AgentAdaptor;
import org.apache.airavata.agents.api.ComputeResourceAdaptor;
import org.apache.airavata.helix.adaptor.SSHJAgentAdaptor;

public class ComputeResourceAdaptorImpl extends SSHJAgentAdaptor implements ComputeResourceAdaptor {

    private final AgentAdaptor jobSubmissionAdaptor;
    private final AgentAdaptor dataMovementAdaptor;

    public ComputeResourceAdaptorImpl(AgentAdaptor jobSubmissionAdaptor, AgentAdaptor dataMovementAdaptor) {
        this.jobSubmissionAdaptor = jobSubmissionAdaptor;
        this.dataMovementAdaptor = dataMovementAdaptor;
    }

    public AgentAdaptor jobSubmissionAdaptor() {
        return jobSubmissionAdaptor;
    }

    public AgentAdaptor dataMovementAdaptor() {
        return dataMovementAdaptor;
    }
}
